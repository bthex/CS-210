import re
import string


def purchaseAmounts(filepath):
    # Open the file in read mode
    text = open(filepath, "r")

    # Create an empty dictionary
    itemPurchased = dict()

    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()

        # Convert the characters in line to
        # lowercase to avoid case mismatch
        line = line.lower()

        # Split the line into words
        words = line.split(" ")

        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in itemPurchased:
                # Increment count of word by 1
                itemPurchased[word] += 1
            else:
                # Add the word to dictionary with count 1
                itemPurchased[word] = 1

    # Print the contents of dictionary
    for key in list(itemPurchased.keys()):
        print(key, ":", itemPurchased[key])

    # Close document
    text.close()

    return 0


def findItem(item):
    file = open("items_purchases.txt", "r")
    # Read content of file to string
    data = file.read()
    # Get number of occurrences of the substring in the string
    occurrences = data.count(item)
    if occurrences == 0:
        print("Item not found")
    else:
        print(occurrences)

    # Close document
    file.close()

    return 0


def createHistogramData(filepath):
    # Open the file in read mode
    text = open(filepath, "r")

    # Create an empty dictionary
    itemPurchased = dict()

    # Loop through each line of the file
    for line in text:
        # Remove the leading spaces and newline character
        line = line.strip()

        # Convert the characters in line to
        # lowercase to avoid case mismatch
        line = line.lower()

        # Split the line into words
        words = line.split(" ")

        # Iterate over each word in line
        for word in words:
            # Check if the word is already in dictionary
            if word in itemPurchased:
                # Increment count of word by 1
                itemPurchased[word] += 1
            else:
                # Add the word to dictionary with count 1
                itemPurchased[word] = 1
    # Close document
    text.close()

    # Print the contents of dictionary
    with open("frequency.dat", 'w') as newfile:
        for key, word in itemPurchased.items():
            newfile.write('{} {}\n'.format(key, word))

    newfile.close()
    return 0
