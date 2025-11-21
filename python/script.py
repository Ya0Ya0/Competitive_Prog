import os
import shutil

# Get the list of all files in the desktop
desktop_path = os.path.join(os.path.expanduser("~"), "Desktop")
files = [os.path.join(desktop_path, file) for file in os.listdir(desktop_path) if os.path.isfile(os.path.join(desktop_path, file))]

# Create a dictionary to map extensions to folders
ext_to_folder = {
    ".pdf": "PDFs",
    ".doc": "Documents",
    ".docx": "Documents",
    ".txt": "Text Files",
    ".jpg": "Images",
    ".png": "Images",
    ".gif": "Images",
    ".mp4": "Videos",
    ".mp3": "Music",
    ".avi": "Videos",
    ".exe": "Ejecutable",
    ".wav": "Music"
}

# Create the folders if they don't exist
for extension, folder_name in ext_to_folder.items():
    folder_path = os.path.join(desktop_path, folder_name)
    os.makedirs(folder_path, exist_ok=True)

# Move the files to their respective folders
for file in files:
    extension = os.path.splitext(file)[1].lower()
    if extension in ext_to_folder:
        folder_path = os.path.join(desktop_path, ext_to_folder[extension])
        shutil.move(file, folder_path)

print("Desktop cleaned and files organized!")