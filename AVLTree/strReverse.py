

s = "hellooo0oojdjaosdjoasjdoasdoasodjoasjdoasjasjdasojdoasjdo"

def isPalindrome(s): 

  if len(s) == 0 or len(s) == 1: 
    return True 

  if s[0] == s[-1]: 
    return isPalindrome(s[1:-1]) 

  return False

def reverse(s): 
  if s == "": 
    return "" 
  
  return  s[-1] + reverse(s[:-1])

def decimalToBinary(num):
    # Base case 
  if num == 1: 
    return "1" 
  if num == 0:
    return "0"
  
  return decimalToBinary(num//2) + str(num%2) 

print(decimalToBinary(20)) 

class Node: 
  def __init__(self, _val):
    self.next = None 
    self.val = _val 
  def setNext(self, node): 
    self.next = node 
  def getNext(self): 
    return self.next 
  def getVal(self):
    return self.val 
  
  

class LinkedList: 
  def __init__(self) -> None:
      self.head = None 
  
  def insert(self, node, val):
    if not node: 
      self.head = Node(val)
      return
    if not node.next:
      node.next = Node(val)
      return 
    self.insert(node.next,val)

  def printList(self, node): 
    if not node:
      return
    print(node.val) 
    self.printList(node.next)
  def printReverse(self, node):
    if not node: 
      return 
    self.printReverse(node.next) 
    print(node.val)
  def reverseList(self, node):
    if not node or not node.next: 
      return node 
    pointer = self.reverseList(node.next) 
    pointer.next.next = node 
    pointer.next = None 
    return pointer

myList = LinkedList() 
myList.insert(myList.head,40) 
myList.insert(myList.head,30) 
myList.insert(myList.head,20) 
myList.insert(myList.head,10) 
myList.insert(myList.head,0)

myList.printList(myList.head)
print("------")
myList.printReverse(myList.head) 
myList.reverseList(myList.head) 
myList.printList(myList.head)

