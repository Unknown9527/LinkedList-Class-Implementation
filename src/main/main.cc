#include <iostream>
#include "src/lib/solution.h"

using namespace std;

int main()
{
    const vector<int> input0 = {1,2,3,4,5,6,7};
    
    int i = -1;

    SinglyLinkedList WorkVec(input0, i);

    cout << "Vector Size::" << WorkVec.size() << endl;
    cout << "?Empty::" << WorkVec.empty()<<endl;
    WorkVec.push_back(9);
    WorkVec.push_front(-1);
    
    cout << "Push Back::" << WorkVec.back() << endl;
    cout << "Push Front::" << WorkVec.front() << endl;
    WorkVec.print();
    
    WorkVec.pop_front();
    // WorkVec.pop_front();
    // WorkVec.print();
    WorkVec.pop_back();
    // WorkVec.pop_back();
    cout<<"Pop Front & Back::";
    WorkVec.print();

    int InceIth = 2;
    ListNode *Ince = new ListNode(InceIth);
    WorkVec.insert_after(Ince, 999);
    cout<<"Insert " << Ince->val << " after the " << InceIth << " place:: ";
    WorkVec.print();
    ListNode *EraObj1 = new ListNode(999);
    WorkVec.erase(EraObj1);
    cout << "Erase " << EraObj1->val << " from list::";
    WorkVec.print();

    // WorkVec.print();
    int IthLoc = 3;
    cout << "The current last item pointer::" << WorkVec.GetBackPointer()->val << endl;
    cout << "The current " << IthLoc << "rd pointer now is::" << WorkVec.GetIthPointer(IthLoc)->val << endl;

    // WorkVec.print();
    return EXIT_SUCCESS;

}
