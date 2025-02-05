// /**
//  * Definition of doubly linked list:
//  *
//  * class Node {
//  * public:
//  *      int data;
//  *      Node *prev;
//  *      Node *next;
//  *      Node() {
//  *          this->data = 0;
//  *          this->prev = NULL;
//  *          this->next = NULL;
//  *      }
//  *      Node(int data) {
//  *          this->data = data;
//  *          this->prev = NULL;
//  *          this->next = NULL;
//  *      }
//  *      Node (int data, Node *next, Node *prev) {
//  *          this->data = data;
//  *          this->prev = prev;
//  *          this->next = next;
//  *      }
//  * };
//  *
//  *************************************************************************/

// Tc - O(n) SC-O(1)
// Node *deleteAllOccurrences(Node *head, int k) {
//   // Write your code here
//   Node *temp = head;
//   while (temp != NULL) {
//     // means the current node is equal to k
//     if (temp->data == k) {
//       if (temp == head) {
//         head = temp->next;
//       }

//       Node *NextNode = temp->next;
//       Node *prevNode = temp->prev;
//       if (NextNode != NULL) NextNode->prev = prevNode;
//         if (prevNode != NULL)
//           prevNode->next = NextNode;

//       delete temp;
//       temp = NextNode;

//     } else {
//       temp = temp->next;
//     }
//   }
//   return head;
// }
