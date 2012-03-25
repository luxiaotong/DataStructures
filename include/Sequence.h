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
        void Josephus(int num, int start, int out);         //Ô¼Éª·ò»·
        //void Insert(elemtye arr[], IntType data);
        char * compare_12(IntType arrA[], IntType arrB[]);
        //virtual ~Sequence();
};

#endif // SEQUENCE_H
