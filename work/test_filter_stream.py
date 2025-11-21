import pytest
from filter import filter_stream # replace with the actual module name

import pytest
from pathlib import Path

# Assuming we've already imported filter_stream from the module
# from your_module import filter_stream

def test_filter_stream_empty_lines(tmp_path: Path):
    # Create a temporary file with empty lines
    test_file = tmp_path / "test_file.txt"
    test_file.write_text("\n\nline1\n\nline2\n\n")

    expected_output = ["line1", "line2"]
    actual_output = filter_stream(test_file)

    assert actual_output == expected_output


def test_filter_stream_comments(tmp_path: Path):
    # Create a temporary file with comments
    test_file = tmp_path / "test_file.txt"
    test_file.write_text("#comment1\n//comment2\nline1\nline2\n")

    expected_output = ["line1", "line2"]
    actual_output = filter_stream(test_file)

    assert actual_output == expected_output


def test_filter_stream_whitespace(tmp_path: Path):
    # Create a temporary file with leading/trailing whitespaces
    test_file = tmp_path / "test_file.txt"
    test_file.write_text("  line1  \n  line2  \n")

    expected_output = ["line1", "line2"]
    actual_output = filter_stream(test_file)

    assert actual_output == expected_output


def test_filter_stream_mixed(tmp_path: Path):
    # Create a temporary file with a mixture of all cases
    test_file = tmp_path / "test_file.txt"
    test_file.write_text("  #comment1  \n\n  //comment2  \n line1 \n\n line2 \n")

    expected_output = ["line1", "line2"]
    actual_output = filter_stream(test_file)

    assert actual_output == expected_output

# Command to run tests typically would be:
# pytest test_filter_stream.py