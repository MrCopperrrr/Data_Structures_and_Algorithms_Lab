template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index<0 || index >=count) {
        throw std::out_of_range("");
    }
    Node* tmp=head;
    if (index==0){
        head=tmp->next;
        T c= tmp->data;
        delete tmp;
        count--;
        return c;
    }
    for (int i=0;i<index-1;i++){
        tmp=tmp->next;
    }
    if (index == count-1){
        tail=tmp;
        T d= tmp->next->data;
        delete tmp->next;
        tail->next= NULL;
        count--;
        return d;
    }
    Node *a = tmp->next;
    T b = a->data;
    tmp->next=a->next;
    delete a;
    count--;
    return b;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    Node* tmp=head;
    int a=-1;
    if (tmp->data== item) {removeAt(0); return 1; }
    for (int i=0;i<count-1;i++){
        if (tmp->next->data==item){ a=i+1; break;}
        tmp=tmp->next;
    }
    if (a==-1) return 0;
    else {
        Node *a = tmp->next;
        if (a==tail) {count--;tail=tmp;delete a; return 1;}
        tmp->next=a->next;
        delete a;
        count--;
        return 1;
    }
    
}

template<class T>
void SLinkedList<T>::clear(){
    Node* run= head;
    for (int i=0;i<count;i++){
        Node * tmp=run;
        run=run->next;
        delete tmp;
    }
    head=NULL;
    tail=NULL;
    count=0;
}