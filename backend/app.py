from flask import Flask, request, send_from_directory
import os

app = Flask(__name__, static_folder='../website/static')
UPLOAD_FOLDER = 'uploads' 
ALLOWED_EXTENSIONS = {'mp4', 'avi', 'mov'} 

if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS

@app.route('/')
def index():
    return send_from_directory('../website', 'index.html')

@app.route('/upload-video', methods=['POST'])
def upload_video():
    if 'file' not in request.files:
        return 'No file part', 400
    file = request.files['file']
    if file.filename == '':
        return 'No selected file', 400
    if file and allowed_file(file.filename):
        filename = os.path.join(UPLOAD_FOLDER, file.filename)
        file.save(filename)
        return 'File uploaded successfully', 200
    return 'Invalid file type', 400

if __name__ == '__main__':
    app.run(debug=True)
