//
// Created by barba on 23.03.2025.
//

#ifndef NODUPLO_H
#define NODUPLO_H


class noDuplo {
    public:
        noDuplo();

    private:
        struct NodeDuplo {
            int data;
            NodeDuplo* next;
            NodeDuplo* prev;

            NodeDuplo(int val){
                data = val;
                next = nullptr;
                prev = nullptr;
            }
        };
};


#endif //NODUPLO_H
