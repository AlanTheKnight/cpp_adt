package main

import "fmt"

type Node struct {
	Value       int
	Left, Right *Node
}

func (root *Node) insert(value int) *Node {
	if root == nil {
		return &Node{Value: value}
	} else if value < root.Value {
		root.Left = root.Left.insert(value)
	} else {
		root.Right = root.Right.insert(value)
	}
	return root
}

func removeNodesNotInRange(node *Node, min int, max int) *Node {
	if node == nil {
		return nil
	}

	node.Left = removeNodesNotInRange(node.Left, min, max)
	node.Right = removeNodesNotInRange(node.Right, min, max)

	if node.Value < min {
		return node.Right
	}
	if node.Value > max {
		return node.Left
	}
	return node
}

func (root *Node) print() {
	if root != nil {
		root.Left.print()
		fmt.Print(root.Value, " ")
		root.Right.print()
	}
}

func main() {
	var root = Node{
		1, // значение корня
		nil, nil}
	min := 1 // минимальное и максимальное значения
	max := 2

	root.insert(0)
	root.insert(2)

	removeNodesNotInRange(&root, min, max)

	root.print()
}
