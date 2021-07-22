1、删除链表中的节点
//只能使用这种借尸还魂的方法，一般情况下，删除节点必须有前驱节点

void deleteNode(ListNode* node) {
        ListNode* node1 = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete node1;
    }
	
2、删除链表的倒数第N个节点
//快慢节点往后走，然后删除慢指针后面那个节点

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while((n--)>0 && fast != nullptr){
            fast = fast->next;
        }
        if(n > 0){
            return head;
        }else if(fast == nullptr){
            slow = slow->next;
            delete head;
            return slow;
        }else{
            while(fast->next != nullptr){
                fast = fast->next;
                slow = slow->next;
            }
            slow->next = slow->next->next;
            return head;
        }
    }
	
3、反转链表
//基础问题，循环让下一个指向前面那个即可

ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = head;
        while(c){
            b = c;
            c = c->next;
            b->next = a;
            a = b;
        }
        return b;
    }
	
4、合并两个有序链表
//可以逐个比较，拆下小的节点链接在一个新头上，也可以使用如下递归，充分链接每个节点

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr){
            return l1 == nullptr?l2:l1;
        }
        ListNode* head = nullptr;
        if(l1->val <= l2->val){
            head = l1;
            head->next = mergeTwoLists(l1->next, l2);
        }else{
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        return head;
    }
	
5、回文链表
//后半部分翻转，首尾开始比较，不同直接return

bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
		bool A = true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!= nullptr && fast->next->next!=nullptr){
            fast = fast->next->next;                     //找到中间节点
            slow = slow->next;
        }
        fast = slow->next;                           //fast为后半部分头节点
        slow->next = nullptr;
        ListNode* p = slow;
        ListNode* q = nullptr;
        while(fast!=nullptr){
            q = fast;
            fast = fast->next;
            q->next = p;
            p = q;
        }                                         //反转完毕
        p = head;
        fast = q;
        while(p!=nullptr && fast!=nullptr){        //挨个比较
            if(p->val == fast->val){
                p = p->next;
                fast = fast->next;
            }else{
                A =  false;                  //没把表恢复，还不能return
            }
        }
        fast = nullptr;
        p = nullptr;
        while(q!=nullptr){
            p = q;
            q = q->next;
            p->next = fast;
            fast = p;
        }
        return A;
    }
	
6、环形链表
//有环两个快慢指针定会相遇

bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next!= nullptr &&fast->next->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                return true;
            }
        }
        return false;
    }