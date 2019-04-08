/*
25. Reverse Nodes in k-Group
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
Example:

Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

当时笔试时，输入输出都要带"[,]",所以格式很难搞，我得输入有错误
当时ListNode初始化没搞好，所以没做出来
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
ListNode* reverseKlist(ListNode* head, int k){
    ListNode* pre;
    ListNode* p = head;
    ListNode* q = head;
    if(!p || k ==1) return p;
    for(int i=1; i<k; i++){
        if(!q->next) return head;
        q = q->next;
    }
    pre = p;
    head = q;
    while(p->next!=head){
        q = p->next;
        p->next = p->next->next;
        q->next = pre;
        pre = q;
    }
    p->next = reverseKlist(head->next, k);
    head->next = pre;
    return head;
}

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr||k<2 )
            return head;
        ListNode *next_group = head;
        for(int i=0;i<k;i++){
            if(next_group)
                next_group=next_group->next;
            else
                return head;
        }
        ListNode *new_next_group=reverseKGroup(next_group,k);
        ListNode *prev =nullptr,*cur=head;
        while(cur!=next_group){
            ListNode *q = cur->next;
            cur->next = prev?prev:new_next_group;
            prev = cur;
            cur = q;
        }//use three points prev¡¢cur¡¢q to mark the node need to reverse£¬in the end£¬prev is the head node of the next group need to reverse
        return prev;
}
void printList(ListNode* head){
    ListNode* p = head;
    cout<<"[";
    while(p!=nullptr){
        cout<<p->val;
        p = p->next;
        if(p == nullptr) break;
        cout<<",";
    }
    cout<<"]";
}
int main(){
    ListNode* l = new ListNode(0);
    char c;
    vector<char> vc;
    string line1;
    int line2;
    getline(cin, line1);
    cin>>line2;
    ListNode *p = l;
    stringstream ss(line1);
    while(ss>>c){
        vc.push_back(c);
    }
    for(int i=0;i<vc.size()-3;i++){
            if(vc[i]!=',' && vc[i]!='[' && vc[i]!=']'){
                p->val = vc[i]-'0';
                ListNode* temp = new ListNode(0);
                p->next = temp;
                p = temp;
            }
    }
    p->val = int(vc[vc.size()-2]-'0');
    p->next = nullptr;
    cout<<"cin finished"<<endl;
    printList(l);
    ListNode* r = reverseKGroup(l, line2);
    cout<<endl;
    cout<<"reverse finished"<<endl;
    printList(r);
    return 0;
}
