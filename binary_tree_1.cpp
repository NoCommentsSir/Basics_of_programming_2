
#include "Node.h"
#include "Tree.h"
#include "ForwardIterator.h"
#include "BackwardIterator.h"

using namespace std;

int main()
{
    cout << "creating tree.. \n";
    BinTree<int> test;
    test.push(6);
    test.push(4);
    test.push(1);
    test.push(5);
    test.push(7);
    test.push(3);
    test.push(1);
    test.push(0);

    cout << "creating forward iterator.. \n";
    ForwardIterator<int> it_test(&test);

    cout << "starting forward iterator.. \n";
    while (it_test.hasMore())
    {
        it_test.move();
        std::cout << it_test.current->data << ' '; 
    }

    cout << "\ncreating backward iterator.. \n";
    BackwardIterator<int> it_test_back(&test);

    cout << "starting backward iterator.. \n";
    while (it_test_back.hasMore())
    {
        it_test_back.move();
        std::cout << it_test_back.current->data << ' '; 
    }
}

