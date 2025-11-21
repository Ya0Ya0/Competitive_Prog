import os
import shutil

# Set the path to your desktop
desktop_path = os.path.join(os.path.expanduser("~"), "Desktop")

# Create a function to create folders if they don't exist
def create_folder_if_not_exists(folder_path):
   if not os.path.exists(folder_path):
       os.mkdir(folder_path)
    
def move_files_to_folders(file_path, extension_folder_map):
    extension = os.path.splitext(file_path)[1].lower()
    
    # Check if the file has a valid extension and a corresponding folder
    if extension in extension_folder_map:
        folder_path = os.path.join(desktop_path, extension_folder_map[extension])
        create_folder_if_not_exists(folder_path)  
        shutil.move(file_path, folder_path)

def main():
      #Map extensions to their corresponding folder names
    extension_folder_map = {
       ".txt": "Text Files",
       ".pdf": "PDF Files",
       ".docx": "Word Files",
       ".jpeg": "Image Files",
       ".png": "Image Files",
       ".gif": "Image Files",
        # Add more extensions as needed
    }
     
 # Loop through the desktop files
    for file_name in os.listdir(desktop_path):
        file_path = os.path.join(desktop_path, file_name) 
        if os.path.isfile(file_path):
            move_files_to_folders(file_path, extension_folder_map)

if __name__ == "__main__":
    main()  