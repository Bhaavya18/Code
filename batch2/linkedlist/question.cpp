#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
  ListNode* midbyidx(ListNode* head)
  {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast!=nullptr && fast->next!=nullptr && fast->next->next!=nullptr)
      {
          slow=slow->next;
          fast=fast->next->next;
      }
      return slow;
  }
  ListNode* reverselist(ListNode* head)
  {
      ListNode*  prev=nullptr;
      ListNode* cur=head;
      ListNode* forw=nullptr;
      while(cur!=nullptr)
      {
          forw=cur->next;
          cur->next=prev;
          prev=cur;
          cur=forw;
      }
      return prev;
  }
  bool isPalindrome(ListNode* head) {
   if(head==nullptr || head->next==nullptr)
   return true;

    ListNode* mid=midbyidx(head);
    ListNode* nhead=mid->next;
    mid->next=nullptr;
    nhead=reverselist(nhead);
    ListNode* cur1=head;
    ListNode* cur2=nhead;
    while(cur1!=nullptr && cur2!=nullptr)
    {
        if(cur1->val!=cur2->val)
        return false;

        cur1=cur1->next;
        cur2=cur2->next;
    }    
       return true; 
    }

     bool hasCycle(ListNode *head) {
      if(head==nullptr || head->next==nullptr) //when only ine node present;
       return false;

       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=nullptr && fast->next!=nullptr) 
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           break;
       }
       return slow==fast;
    }

    ListNode *detectCycle(ListNode *head) {
         if(head==nullptr || head->next==nullptr) //when only one node present;
       return nullptr;

       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=nullptr && fast->next!=nullptr) 
       {
           slow=slow->next;
           fast=fast->next->next;
           if(slow==fast)
           break;
       }
       if(slow==fast)
     {  slow=head;
       while(slow!=fast)
       {
           slow=slow->next;
           fast=fast->next;
       }
       return slow;
     }
     return nullptr;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(headA==nullptr  || headB==nullptr)
      return nullptr;
      if(headA->next==nullptr && headB->next==nullptr && headA->val==headB->val)
      return headA;

       ListNode* cur=headA;
       ListNode* tail=headA;
       while(cur!=nullptr)
       {
           tail=cur;
           cur=cur->next;
       }
       tail->next=headB;
       ListNode* ans=detectCycle(headA);
       return ans; 
    }
    //****leetcode ques21*********************//
    ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
     if(A==nullptr)
     return B;
     if(B==nullptr)
     return A;

     ListNode* head= new ListNode(-1);
     ListNode* cur=head;
     while(A!=nullptr && B!=nullptr)
     {
         if(A->val<=B->val)
         {
             cur->next=A;
             A=A->next;
         }
         else
         {
            cur->next=B;
            B=B->next;
         }
         cur=cur->next;
         
     }
     if(A!=nullptr)   //left linkedlist
     cur->next=A;
     else if(B!=nullptr)
     cur->next=B;

    return head->next;

    }
    //************leetcode ques148********************************//
     ListNode* sortList(ListNode* head) {
      if(head==nullptr || head->next==nullptr)
      return head;

      ListNode*mid=midbyidx(head);
      ListNode* nhead=mid->next;
      mid->next=nullptr;
   ListNode* a=sortList(head);
   ListNode*b=sortList(nhead);

      return mergeTwoLists(a,b);

    }
    //*****leetcode23***********************//
     ListNode* mergeKLists_(int si,int ei,vector<ListNode*>& lists) {
        if(si==ei)
        return lists[si];

        if(si+1==ei)
        return mergeTwoLists(lists[si],lists[ei]);

        int mid=(si+ei)/2;
        ListNode* a=mergeKLists_(si,mid+1,lists);
        ListNode* b=mergeKLists_(mid+1,ei,lists);

        return mergeTwoLists(a,b);
       }
     ListNode* mergeKLists(vector<ListNode*>& lists) {
         return mergeKLists_(0,lists.size()-1,lists);
       }
        
    //**********************leetcode ques143************************************************//      
  void reorderList(ListNode* head) {
    if(head==nullptr || head->next==nullptr)
     return;
    
    ListNode* mid=midbyidx(head);
    ListNode* nhead=mid->next;
    mid->next=nullptr;
    nhead=reverselist(nhead);
    ListNode*cur1=head;
    ListNode* cur2=nhead;
    ListNode* forw1=nullptr;
    ListNode* forw2=nullptr;
    while(cur1!=nullptr && cur2!=nullptr)
    {
       forw1=cur1->next;
       forw2=cur2->next;

       cur1->next=cur2;
       if(forw1!=nullptr)
       cur2->next=forw1;
   
   cur1=forw1;
   cur2=forw2;
    }

    }  
 //*****************leetcode ques328*****************************************//
  ListNode* oddEvenList(ListNode* head) {
     if(head==nullptr || head->next==nullptr)
      return head;

      ListNode* odd=new ListNode(-1);
      ListNode*cur1=odd;
      ListNode* even=new ListNode(-1);
      ListNode* cur2=even;
      ListNode* cur0=head;
      int nodecount=0;
      while(cur0!=nullptr)
      {
          if(nodecount%2!=0)
          {
              cur1->next=cur0;
              cur1=cur1->next;
          }
          else
          {
              cur2->next=cur0;
              cur2=cur2->next;
          }
          cur0=cur0->next;
          
      }

      cur2->next=nullptr; //to tell the list it is finally over otherwise you would get heap use after freeing error
      cur1->next=even->next;
      return odd->next;

    }    