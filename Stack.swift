//
//  File.swift
//  
//
//  Created by Latish Pavan on 10/04/20.
//

import Foundation

class Stack<Type> {
    private var arr = [Type]()
    var count: Int {
        return arr.count
    }
    
    func push(_ item: Type) {
        arr.append(item)
    }
    
    func pop() -> Type {
        return arr.popLast()!
    }
    
    func top() -> Type {
        return arr.last!
    }
}

