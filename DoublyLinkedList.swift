//
//  File.swift
//  
//
//  Created by Latish Pavan on 08/04/20.
//

import Foundation

class ListNode<Type>: CustomStringConvertible {
    var description: String {
        return "\(value)"
    }
    
    var value: Type
    var previous: ListNode<Type>?
    var next: ListNode<Type>?
    
    init(val: Type) {
        value = val
    }
}

class DoublyLinkedList<Type>: CustomStringConvertible {
    private var head: ListNode<Type>?
    private var tail: ListNode<Type>?
    
    var description: String {
        var node = head
        var linkedListString = ""
        
        while node != nil {
            linkedListString += "\(node!.value) -> "
            node = node?.next
        }
        
        return linkedListString
    }
    
    func prepend(_ node: ListNode<Type>) {
        if head == nil { // list is empty
            head = node
            tail = node
        } else { // list is not empty
            head!.previous = node
            node.next = head
            head = node
        }
    }
    
    func append(_ node: ListNode<Type>) {
        if tail == nil {
            head = node
            tail = node
        } else {
            tail!.previous = node
            node.previous = tail
            tail = node
        }
    }
    
    func removeFirst() -> ListNode<Type>? {
        if let currentHead = head {
            let nextNodeToHead = currentHead.next
            nextNodeToHead?.previous = nil
            currentHead.next = nil
            head = nextNodeToHead
            return currentHead
        }
        
        return nil
    }
    
    func removeLast() -> ListNode<Type>? {
        if let currentTail = tail {
            let prevNodeToTail = currentTail.previous
            prevNodeToTail?.next = nil
            currentTail.previous = nil
            tail = prevNodeToTail
            return currentTail
        }
        
        return nil
    }
    
    func moveToFirst(_ node: ListNode<Type>) {
        guard head !== node else { return }
        
        if tail === node {
            tail = node.previous
        }
        
        node.previous?.next = node.next
        node.next?.previous = node.previous
        node.next = head
        node.previous = nil
        head?.previous = node
        head = node
    }
}
