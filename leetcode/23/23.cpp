#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (auto list : lists) {
            if (list) pq.push({list->val, list});
        }
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while (!pq.empty()) {
            auto [val, node] = pq.top();
            pq.pop();
            cur->next = new ListNode(val);
            cur = cur->next;
            if (node->next) pq.push({node->next->val, node->next});
        }
        return head->next;
    }
};
