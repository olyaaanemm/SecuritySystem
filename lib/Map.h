//
// Created by Ольга Немова on 16.12.2021.
//

#ifndef SECURITYSYSTEM_MAP_H
#define SECURITYSYSTEM_MAP_H


//
// Created by Ольга Немова on 14.12.2021.
//

#ifndef XXX_MAP_XXX
#define XXX_MAP_XXX
#include <iostream>
#include <utility>
#include <random>
#include <limits.h>
#include <memory>
#include <array>
#include <stdexcept>
#include <vector>
#include <queue>
#include "Cell.h"

namespace Security {
    template<typename Key_T, typename Mapped_T>
    class Map{
    public:
        class Node;
    private:
        int current_size = 0;
        Node* head;
        int curr_height = 0;
    public:
        //Member Type
        class Iterator;
        class Node {
        public:
            friend class Map;
            Node *right;
            Node *left;
            Node *parent;
            Key_T key;
            std::pair<Key_T, Mapped_T> pair_;
            Mapped_T value;

            Node(Key_T keyed, Mapped_T valued) {
                this->value = valued;
                this->key = keyed;
                this->pair_ = std::pair<Key_T, Mapped_T>(key, value);
                this->left = nullptr;
                this->right = nullptr;
                this->parent = nullptr;
            };
            Node(const Node &rhs)
                    : key(rhs.key), value(rhs.value){
                this->pair_ = std::pair<Key_T, Mapped_T>(key, value);
                this->left = nullptr;
                this->right = nullptr;
                this->parent = nullptr;
            };
        };

        //Constructors and Assignment
    public:
        Map();
        ~Map();
        Iterator begin() const;
        Iterator end() const;
        [[nodiscard]] size_t size() const;
        [[nodiscard]] bool empty() const;
        //[[nodiscard]] size_t count(const Key_T& key) const;
        [[nodiscard]] int current_height() const;
        bool insert( const std::pair<Key_T, Mapped_T> & item);
        Iterator find(const Key_T &search) const;
        void clear() noexcept;
        void erase (Iterator);
        void erase (Iterator, Iterator);
        Mapped_T& at(const Key_T& key);
        void show();
        const Mapped_T& at( const Key_T& key ) const;
        Mapped_T& operator[](const Key_T& ) noexcept;
        const Mapped_T& operator[](const Key_T& ) const noexcept;
    private:
        //Size
        void show(Node *);
        bool erase_(const Key_T&);
        bool isLeaf( Node* node);
        void destroy_tree(Node * );
        void destroy_tree();
        Node* find_(const Key_T &, Node*);
        Node* leftMax(Node*);
        void deletDeepest(Node* root, Node* d_node);
    public:
        class Iterator{
        private:
            Node* target;
            std::queue<Node*> que;
            void BreathFill(Node* node) {
                if (node== nullptr) {
                    return;
                }
                this->que.push(node);
                BreathFill(node->left);
                BreathFill(node->right);
            }
            void createList() {
                while(!this->que.empty()) {
                    this->que.pop();
                }
                BreathFill(this->target);
            }
        public:
            friend class Map;
            Iterator() {
                this->target = nullptr;
            }
            Iterator(Node* pos){
                this->target = pos;
                BreathFill(this->target);
            };
            friend bool operator==(const Iterator &lhs, const Iterator &rhs){
                return (lhs.target == rhs.target);
            };
            friend bool operator!=(const Iterator &lhs, const Iterator &rhs){
                return (lhs.target != rhs.target);
            };

            Iterator& operator++(){
                if(!this->que.empty()) {
                    Node* node = this->que.front();
                    while (this->target == node) {
                        this->que.pop();
                        node = this->que.front();
                    }
                    this->target = node;
                    this->que.pop();
                    return *(this);
                }
                this->target = nullptr;
                return *this;
            };

            Iterator operator++(int){
                Iterator c_ = *this;
                ++(*this);
                return c_;
            };
            Iterator& operator=(const Iterator& it) {
                if (*this == it) {
                    return *(this);
                }
                this->target = it.target;
                this->createList();
                return *this;
            }
            std::pair<Key_T, Mapped_T> *operator->() const{
                return &this->target->pair_;
            };
            std::pair<Key_T, Mapped_T> &operator*() const{
                std::pair<Key_T, Mapped_T> *pair = std::make_pair(this->target->key, this->target->value);
                return *pair;
            };
        };
    };

    //Map Default Constructor
    template<typename Key_T, typename Mapped_T>
    Map<Key_T, Mapped_T>::Map(){
        this->head = nullptr;
        this->current_size = 0;
        this->curr_height = 0;
    }

    //Map destructor
    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::destroy_tree(Node *leaf) {
        if(leaf != nullptr) {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);
            delete leaf;
        }
    }
    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::destroy_tree() {
        destroy_tree(head);
    }

    template<typename Key_T, typename Mapped_T>
    bool Map<Key_T, Mapped_T>::insert( const std::pair<Key_T, Mapped_T> & item) {
        Node* pioneer = new Node(item.first, item.second);
        Node* prev;
        if (this->head == nullptr) {
            this->head = pioneer;
            this->curr_height++;
            this->current_size++;
            return true;
        }
        else {
            Node* tmp;
            tmp = head;
            while (tmp != nullptr) {
                prev = tmp;
                if (item.first > tmp->key) {
                    tmp = tmp->right;
                }
                else if (item.first == tmp->key) {
                    throw std::out_of_range("Key is already exist in map");
                }
                else {
                    tmp = tmp->left;
                }
            }
            if (isLeaf(prev)) {
                this->curr_height++;
                this->current_size++;
            }
            else {
                this->current_size++;
            }
            if (item.first < prev->key) {
                prev->left = pioneer;
                pioneer->parent = prev;
            }
            else {
                prev->right = pioneer;
                pioneer->parent = prev;
            }
        }
        return true;
    };
    template<typename Key_T, typename Mapped_T>
    Map<Key_T, Mapped_T>::~Map(){
        destroy_tree();
    }
    template<typename Key_T, typename Mapped_T>
    bool Map<Key_T, Mapped_T>::isLeaf( Node* node) {
        if (node == nullptr) {
            return false;
        }
        return ((node->left == nullptr) && (node->right == nullptr));
    }
    template<typename Key_T, typename Mapped_T>
    [[nodiscard]] int Map<Key_T, Mapped_T>::current_height() const{
        return this->curr_height;
    };
    //Iteratorsn()
    template<typename Key_T, typename Mapped_T>
    typename Map<Key_T, Mapped_T>::Iterator Map<Key_T, Mapped_T>::begin() const {
        Iterator it(head);
        return it;
    }
    template<typename Key_T, typename Mapped_T>
    typename Map<Key_T, Mapped_T>::Iterator Map<Key_T, Mapped_T>::end() const {
        return Iterator(nullptr);
    }
    //iterator find
    template<typename Key_T, typename Mapped_T>
    typename Map<Key_T, Mapped_T>::Iterator Map<Key_T, Mapped_T>::find(const Key_T &search) const {
        Node* tmp = this->head;
        while (tmp != nullptr) {
            if(tmp->key == search){
                return Iterator(tmp);
            }
            else if (search > tmp->key) {
                tmp = tmp->right;
            }
            else if (search < tmp->key) {
                tmp = tmp->left;
            }
        }
        return end();
    }

    //Size
    template<typename Key_T, typename Mapped_T>
    size_t Map<Key_T, Mapped_T>::size() const{
        return this->current_size;
    }

    //Empty
    template<typename Key_T, typename Mapped_T>
    bool Map<Key_T, Mapped_T>::empty() const {
        return this->head == nullptr;
    }

    template<typename Key_T, typename Mapped_T>
    typename Map<Key_T, Mapped_T>::Node *Map<Key_T, Mapped_T>::find_(const Key_T & item, Node* leaf) {
        if (leaf != nullptr) {
            if (item ==leaf->key) {
                return leaf;
            }
            if (item < leaf->key) {
                return find_(item, leaf->left);
            }
            else {
                return find_(item, leaf->right);
            }
        }else {
            return nullptr;
        }
    }

    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::clear() noexcept {
        destroy_tree();
        this->head = nullptr;
    }

    template<typename Key_T, typename Mapped_T>
    const Mapped_T &Map<Key_T, Mapped_T>::at(const Key_T &key) const {
        const Node* find = find_(key, this->head);
        if (find == nullptr) {
            throw std::out_of_range("Key is not found in map");
        }
        return find->value;
    }

    template<typename Key_T, typename Mapped_T>
    Mapped_T &Map<Key_T, Mapped_T>::at(const Key_T &key) {
        Node* find = find_(key, this->head);
        if (find == nullptr) {
            throw std::out_of_range("Key is not found in map");
        }
        return find->value;
    }

    template<typename Key_T, typename Mapped_T>
    typename Map<Key_T, Mapped_T>::Node *Map<Key_T, Mapped_T>::leftMax(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        else {
            while(node->right!= nullptr) {
                node = node->right;
            }
            return node;
        }
    }

    template<typename Key_T, typename Mapped_T>
    bool Map<Key_T, Mapped_T>::erase_(const Key_T& key) {
        if (head == nullptr) {
            return false;
        }
        if (isLeaf(head)) {
            if (head->key == key) {
                this->head = nullptr;
                return true;
            }
            else {
                return false;
            }
        }

        std::queue<Node*> q;
        q.push(head);

        Node* temp;
        Node* key_node = nullptr;

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->key == key)
                key_node = temp;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        if (key_node != nullptr) {
            Key_T x = temp->key;
            Mapped_T y = temp->value;
            std::pair<Key_T, Mapped_T> pair = temp->pair_;
            deletDeepest(head, temp);
            key_node->key = x;
            key_node->value = y;
            key_node->pair_ = pair;
            return true;
        }
        return false;
    }

    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::deletDeepest(Map::Node *root, Map::Node *d_node) {
        std::queue<Node*> q;
        q.push(this->head);
        // Do level order traversal until last node
        struct Node* temp;
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == d_node) {
                temp = nullptr;
                delete (d_node);
                return;
            }
            if (temp->right) {
                if (temp->right == d_node) {
                    temp->right = nullptr;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->right);
            }

            if (temp->left) {
                if (temp->left == d_node) {
                    temp->left = nullptr;
                    delete (d_node);
                    return;
                }
                else
                    q.push(temp->left);
            }
        }

    }

    template<typename Key_T, typename Mapped_T>
    Mapped_T &Map<Key_T, Mapped_T>::operator[](const Key_T& key) noexcept {
        Node* find = this->find_(key, head);
        if (find == nullptr) {
        }
        else {
            return find->value;
        }
    }
    template<typename Key_T, typename Mapped_T>
    const Mapped_T &Map<Key_T, Mapped_T>::operator[](const Key_T& key) const noexcept {
        const Node* find = this->find_(key, head);
        if (find == nullptr) {
        }
        else {
            return find->value;
        }
    }

    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::erase(Map::Iterator it) {
        Node* find = find_(it.target->key, it.target);
        if (find == nullptr) {
            return;
        }
        else {
            erase_(it.target->key);
        }
    }
    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::show() {
        show(head);
    }

    template<typename Key_T, typename Mapped_T>
    void Map<Key_T, Mapped_T>::show(Node* node) {
        if (node == nullptr) {
            return;
        }
        show(node->left);
        show(node->right);
        std::cout << node->key << " :: " << node->value << std::endl;
    }
}


#endif


#endif //SECURITYSYSTEM_MAP_H
