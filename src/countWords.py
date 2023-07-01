import re
import os
import collections

# Remove all undesired characters from the file's content
def remove_comments(string):
    # Add a "\n" in the end of the string to avoid errors
    string += "\n"

    string = re.sub(re.compile("/\*[\s\S]*?\*/",re.DOTALL ) ," " ,string) # Remove all block comments
    string = re.sub(re.compile("//.*?\n" ) ," " ,string) # Remove all single-line comments 
    string = re.sub(re.compile("cout.*?\n" ) ," " ,string) # Remove all print statements
    string = re.sub(re.compile("cin.*?\n" ) ," " ,string) # Remove all input statements
    string = re.sub(re.compile("#include.*?\n" ) ," " ,string) # Remove all include statements
    string = re.sub(re.compile("using namespace std.*?\n" ) ," " ,string) # Remove all "using namespace std" statements

    # Remove all words in the black list
    words_black_list = ["main", "true", "false", "endl", "break", "malloc", "sizeof", "struct", "string", "void", "bool", "int", "if", "else", "while", "free", "do", "nullptr", "NULL", "return", "for", "auto", "const", "static", "class", "public", "private", "protected", "template", "typename"]
    for word in words_black_list:
        string = re.sub(r"\b{}\b".format(word), " ", string)

    # Remove numerical values
    string = re.sub(r"\b\d+\b", " ", string)

    # Remove strings
    string = re.sub(r"\".*?\"", " ", string)

    # Remove all non-letter characters
    string = re.sub(r"[^a-zA-Z0-9_]", " ", string)

    # Return the string without undesired characters
    return string

# Count the frequency of each word in the string
def count_word_frequency(s):
    words = s.split()  # Split the string into words
    counter = collections.Counter(words)  # Count the frequency of each word

    return counter

# Categorize each word as a function or a variable
def categorize_words(word_counter, file_path):

    with open(file_path, 'r', encoding="utf-8", errors="ignore") as file:
        file_content = file.read()
    
    for word in word_counter.keys():
        # Check if the word is followed by a "("
        if re.search(rf'\b{word}\b\(', file_content):
            word_counter[word]["type"] = 'Function'
        else:
            word_counter[word]["type"] = 'Variable'
            
    return word_counter

# Analyze a single file and return the count of functions and variables
def analyze_file(file_path):
    with open(file_path, 'r', encoding="utf-8", errors="ignore") as file:
        content = file.read()

    # Remove all undesired characters from the file's content
    content = remove_comments(content)

    # Count the frequency of each word on content string
    frequency_dict = count_word_frequency(content)

    # Convert "key:value" pairs to "key: {count: value, type: value}"
    for key, value in frequency_dict.items():
        frequency_dict[key] = {'count': value}

    # Check if the word refeers to a function or a variable
    results_dict = categorize_words(frequency_dict, file_path)

    # Split the dictionary into two dictionaries, one for functions and one for variables
    functions_dict, variables_dict = split_dict(results_dict)

    # Order the dictionaries by value (descending order)
    functions_dict = dict(sorted(functions_dict.items(), key=lambda item: item[1], reverse=True))
    variables_dict = dict(sorted(variables_dict.items(), key=lambda item: item[1], reverse=True))

    # Return the ordered dictionaries
    return functions_dict, variables_dict

# Split the dictionary into two dictionaries, one for functions and one for variables
def split_dict(dictionary):
    # Create two empty dictionaries
    functions_dict = {}
    variables_dict = {}

    # Iterate over the dictionary and add the key:value pairs to the corresponding dictionary
    for key, value in dictionary.items():
        if value["type"] == "Function":
            functions_dict[key] = value["count"]
        else:
            variables_dict[key] = value["count"]

    # Return the two dictionaries
    return functions_dict, variables_dict

# Analyze all the files in a directory and return the count of functions and variables
def analyze_files_in_dir(directory=None):

    # If the directory is not provided, use the current directory
    if directory is None:
        directory = os.getcwd()

    # Create two empty dictionaries
    functions_dict = {}
    variables_dict = {}

    # Iterate over all the files in the directory
    for filename in os.listdir(directory):
        if filename.endswith(".cpp") or filename.endswith(".h"):
            # Analyze the file
            functions_frequency, variables_frequency = analyze_file(os.path.join(directory, filename))

            # Add the results to the dictionaries
            functions_dict = {**functions_dict, **functions_frequency}
            variables_dict = {**variables_dict, **variables_frequency}

    # Order the dictionaries by value (descending order)
    functions_dict = dict(sorted(functions_dict.items(), key=lambda item: item[1], reverse=True))
    variables_dict = dict(sorted(variables_dict.items(), key=lambda item: item[1], reverse=True))

    # Return the ordered dictionaries
    return functions_dict, variables_dict


print("=-", "FUNCTIONS", "-="*20, "\n")

# functions_frequency, variables_frequency = analyze_file("testReGex.cpp")
functions_frequency, variables_frequency = analyze_files_in_dir()

# Pretty print the dictionary
for word, count in functions_frequency.items():
    print(f"\t{word} ({count})")

print("\n=-", "Variables", "-="*20, "\n")

# Pretty print the dictionary
for word, count in variables_frequency.items():
    print(f"\t{word} ({count})")
