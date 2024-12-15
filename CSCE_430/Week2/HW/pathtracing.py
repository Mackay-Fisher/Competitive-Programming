try:
    while True:
        line = input()
        if not line:  # Check for empty line if that's a possibility
            break
        # Process the line
        print("Read:", line)
except EOFError:
    print("fileEnded")
