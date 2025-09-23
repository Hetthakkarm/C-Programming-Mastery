__Concepts:__   
  __=>Q:__ its is queue.  
  __=>R:__ it is the rear pointer from where the insertion operation is perfromed.  
  __=>F:__ it is front pointer from where the deletion operation is perfromed.    
  __=>MAX:__ its size of queue.   
  __=>X:__ its the element to insert.     

  __Algorithm Qinsert(Q,F,R,MAX,X)__(to insert an element into the queue)    
  
    1.if(R>=MAX) then    
      print "Queue Overflows"   
      return 0  
    2.R=R+1   
    3.Q[R]=X   
    4.if(F==0) then   
      F=1   
    5.return      
    


  __Algorithm Qdelete(Q,F,R)__(to delete an element from queue)    
  
    1.if(F<=0) then   
      print "Queue underflow"  
      return  
    2.int y=Q[F]  
    3.if(F==R) then     
      F=R=0   
      else       
      F=F+1   
    4.return y  
    
  

  
