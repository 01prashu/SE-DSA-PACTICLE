# Implement all the functions of dictionary using hashing and handle collision with or without Data: set of key value pairs, keys are mapped value keys must be comparable , keys must be unique . Standerd Operation insert , find an delete ...

class hashtable():
    def __init__(self):
        self.size=10
        self.key=[None for i in range (self.size)]
        self.value=[[] for i in range (self.size)]

    def hash_fun(self , key):
        sum=0
        for i in key:
            sum=sum+ord(i)

        return sum %self.size
    
    def insert(self , key ,value):
        i=self.hash_fun(key)
        if(self.key[i]== None):
            self.key[i]=key
            self.value[i]=value
        
        else:
            # collision without replacement
            c=self.size
            
            for j in range(c):
                i=(i+1)%c
                if(self.key[i]== None):
                    self.key[i]=key
                    self.value[i]=value
                    return

        print("Hash Table Full")

    def find_key(self , key):
        i=self.hash_fun(key)

        if(self.key[i]==key):
            return self.value[i]

        else:
            c=self.size
            for j in range(c):
                i=(i+1)%c

                if(self.key[i] == key):
                    return self.value[i]
        
        print("Value not found \n")

    
    def remove(self , key):
        i=self.hash_fun(key)
        if(self.key[i] == key):
            self.key[i]=None
            self.value[i]=[]
        else:
            c=self.size
            for j in range(c):
                i=(i+1)%c
                if(self.key[i] == key):
                    self.key[i]=None
                    self.value[i]=[]
                    return
        
        print("Value not found")

has_table=hashtable()
has_table.insert("Pranav", 28)
has_table.insert("Prashant", 38)
has_table.insert("bharu", 36)
has_table.insert("AppuLove", 34)
print(has_table.key)
print(has_table.value)
print(has_table.find_key("bharu"))
print(has_table.remove("AppuLove"))
print(has_table.key)
            
            