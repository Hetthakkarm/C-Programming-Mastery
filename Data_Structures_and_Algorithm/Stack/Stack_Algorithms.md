__S__:its a stack(array based implementation with size as s[size]).   

__TOP__:Its a top pointer that points to the top element of stack.   

__X__:Its a value to insert.  

__->Algorithm PUSH(S,TOP,X)__(insert at element into the stack)     

   

  1.if(TOP>=size) then,   
        print "stack overflows!"  
        return  
  2.TOP=TOP+1  
  3.S[TOP]=X  
  4.return  


     
__->Algorithm POP(S,TOP)__(to deleted the element pointed by TOP)      

   
  1.if(TOP<=0) then,   
        print "Stack Underflows!"  
        return  
  2.int y = s[TOP]    
  3.TOP=TOP-1   
  4.return y     

    
  


  
