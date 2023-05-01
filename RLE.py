from logging import raiseExceptions

test_str = "AAABBCDDFDD"

def rle_encode(input_str):
    # Check if the input string is empty
    if not input_str:
        raise ValueError("Empty string in input")

    # Check that the string consists only of uppercase characters of the English alphabet
    if not input_str.isupper() or not input_str.isalpha():
        raise ValueError("The string must contain only uppercase English characters")

    # Create a variable to store the encoded string
    encoded_str = ""

    # Initialize the character repetition counter
    char_count = 1

    # Loop through each character in the input string
    for i in range(1, len(input_str)):
        # Compare the current character with the previous one
        if input_str[i] == input_str[i - 1]:
            # Increment the repetition counter
            char_count += 1
        else:
            # If the current character is different from the previous one
            # Add the previous character and its count to the result (if count > 1)
            encoded_str += input_str[i - 1] + (str(char_count) if char_count > 1 else "")
            # Reset the repetition counter
            char_count = 1

    # Add the last character and its count to the result (if count > 1)
    encoded_str += input_str[-1] + (str(char_count) if char_count > 1 else "")

    return encoded_str


print (rle_encode(test_str))
