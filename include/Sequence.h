#ifndef SEQUENCE_H
#define SEQUENCE_H
#define GET_ARRAY_LEN(array, len) {len = sizeof(array) / sizeof(array[0]); }
#define LEN 10
typedef int IntType;

class Sequence
{
    public:
        void SeqInit(IntType *arr);
        void display(IntType arr[]);
        //void Insert(elemtye arr[], IntType data);
        char * compare_12(IntType arrA[], IntType arrB[]);
        //virtual ~Sequence();
};

#endif // SEQUENCE_H
<<<<<<< HEAD

=======
>>>>>>> ed7b7a031090c2300290dcf05c784efd8228439a
