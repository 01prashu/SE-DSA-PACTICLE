# Book consist of chapters , chapters consist of section and section consist of subsection construct a tree and print a nodes, find the time and space complexity

class Node:
    def __init__(self , value):
        self.value=value
        self.children=[]
    
    def add_element(self ,child):
        self.children.append(child)
    # def repre(self ):
    #     return f'{self.value}'

    
def print_tree(book):
    print(book.value)
    for child in book.children:
        print_tree(child)

book=Node("MyBook")
chapter1=Node("Chapter1")
book.add_element(chapter1)
chap2=Node("Chapt2")
book.add_element(chap2)

section1=Node("Section1.1")
chapter1.add_element(section1)
subsection11=Node("Subsection1.1.1")
section1.add_element(subsection11)

print_tree(book)
