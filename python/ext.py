def _get_file_name(image_location: str) -> str:
    file_extension: str = image_location.split('.')[-1]
    file: str = image_location.split('/')[-1].replace(f'.{file_extension}', '')
    file_name: str = file + '.' + file_extension
    
    return file_name
print(_get_file_name("path/to/image.jpg"))  # Output: image.jpg
print(_get_file_name("path/to/image.png"))  # Output: image.png
print(_get_file_name("path/to/image.gif"))  # Output: image.gif
print(_get_file_name("path/to/image"))  # This will cause an error because the file extension is missing

