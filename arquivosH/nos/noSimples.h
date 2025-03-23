//
// Created by barba on 23.03.2025.
//

#ifndef NOSIMPLES_H
#define NOSIMPLES_H



    class noSimples {
    public:
        noSimples();

    private:
        struct NodeSimples {
            int data;
            NodeSimples* next;

            NodeSimples(int val){
                data = val;
                next = nullptr;
            }
        };


};

#endif //NOSIMPLES_H
