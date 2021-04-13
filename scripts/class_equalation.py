class Node:
    def __init__(self, value=0):
        self.value = value

    def __str__(self):
        return str(self.value)


first_node = Node(10)
second_node = Node(12)
third_node = first_node


for node in [first_node, second_node, third_node]:
    if node in [first_node, second_node, third_node]:
        print(True)

print(first_node)
print(second_node)
print(first_node == second_node)
print(first_node == first_node)
print(first_node == third_node)
