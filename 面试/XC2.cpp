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
