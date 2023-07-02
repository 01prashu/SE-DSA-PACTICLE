#To create a ADT that implement set concept A)Add nw ele B) Remove c)Find d) size E)Intersection F) Union G) Subset H) Diffrence btwn two set

def insertset1(data , set1):
    set1.add(data)
    return set1

def insertset2(data , set2):
    set2.add(data)
    return set2

def removedset1(data , set1):
    set1.remove(data)
    return set1

def removedset2(data , set2):
    set2.remove(data)
    return set2

def sizeofset1(set1):
    return len(set1)
def sizeofset2(set2):
    return len(set2)

def intersectionset12(set1 , set2):
    temp_set=set()
    for i in set1:
        if i in set2:
            temp_set.add(i)
    return temp_set

def unionset12(set1 ,set2):
    temp_set=set()
    for i in set1:
            temp_set.add(i)
    
    for i in set2:
        if i not in set1:
            temp_set.add(i)
    return temp_set
# union - intersection = symmetric diff
N1=int(input("Enter Number Of element for set1\n"))
N2=int(input("Enter Number of element for set2\n"))
set1=[]
set2=[]
for i in range(N1):
    data1=int(input("Enter data of set1\n"))
    set1.append(data1)

for i in range(N2):
    data2=int(input("Enter data for set2\n"))
    set2.append(data2)
set1=set(set1)
set2=set(set2)
print(set1)
print(set2)
print(intersectionset12(set1, set2))
print(unionset12(set1, set2))