#Creating a folder, a file inside it and writing something on it

import os
from csv import writer
from csv import reader

folder = input("Please, type the name of the folder: ")
file = input("Please, type the name of the file: ")
message = input("Please, type your text: ")

os.makedirs(folder)
f = open(folder+"/"+file+".txt", "a")
f.write(message)
f.close()
