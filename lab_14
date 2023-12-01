#include <iostream>

using namespace std;

// Список
template <typename T>
class node
{
public:
    string key;
    T value;
    node* next;

    node(string key, T value) // Конструктор
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    node(node& obj) // Конструктор копирования
    {
        this->key = obj.key;
        this->value = obj.value;
        this->next = NULL;
    }

    ~node() // Деструктор
    {
        node* head = this;
        while (head != NULL)
        {
            node* currNode = head;
            head = head->next;
            delete currNode;
        }
    }
};

// Хеш-таблица
template <typename T>
class unordered_map
{
public:
    int numOfElements, capacity;
    node<T>** arr; // Массив, в котором хранятся указатели на node<T>(заголовок списка)

    unordered_map() // Конструктор
    {
        this->capacity = 1;
        this->numOfElements = 0;
        this->arr = new node<T> *[this->capacity];
        this->arr[0] = NULL;
    }

    int hashFunction(string key) // Хеш-функция для хеширования строки
    {
        int bucketIndex;
        long long int sum = 0, factor = 31;
        for (int i = 0; i < key.size(); i++)
        {
            // sum = sum + (ascii значение символа * (простое число ^ x)) % от общего количества ячеек
            // factor = factor * простое число, т.е. простое число ^ x
            sum = ((sum % this->capacity) + ((int(key[i])) * factor) % this->capacity) % this->capacity;
            factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
        }

        bucketIndex = sum;
        return bucketIndex;
    }

    float getLoadFactor()
    {
        // количество элементов в хеш-таблице / общее количество ячеек
        return (float)(this->numOfElements + 1) / (float)(this->capacity);
    }

    void rehashing()
    {
        int oldCapacity = this->capacity;
        node<T>** temp = this->arr; // temp содержит текущий массив

        this->capacity = oldCapacity * 2; // удвоение размера текущей емкости
        this->arr = new node<T> *[this->capacity]; // указывает на новый массив удвоенного размера

        for (int i = 0; i < this->capacity; i++)
        {
            arr[i] = NULL;
        }
        for (int i = 0; i < oldCapacity; i++) // копирование всех предыдущих значений в новый массив
        {
            node<T>* currBucketHead = temp[i];
            while (currBucketHead != NULL) // копирование всего списка
            {
                this->insert(currBucketHead->key, currBucketHead->value); // функция вставки теперь обновила хэш-функцию, так как емкость удвоилась
                currBucketHead = currBucketHead->next;
            }
        }
        delete[] temp; // удаление старого массива из кучи памяти
        return;
    }

    void insert(string key, T value)
    {
        while (this->getLoadFactor() > 0.5f) // при коэффициенте нагрузки > 0,5
        {
            this->rehashing();
        }

        int bucketIndex = this->hashFunction(key);
        if (this->arr[bucketIndex] == NULL) // когда в ячейке нет списка
        {
            node<T>* newNode = new node<T>(key, value);
            arr[bucketIndex] = newNode;
        }
        else // добавление в начало текущего списка
        {
            node<T>* newNode = new node<T>(key, value);
            newNode->next = this->arr[bucketIndex];
            this->arr[bucketIndex] = newNode;
        }
        return;
    }

    int search(string key)
    {
        int bucketIndex = this->hashFunction(key); // получение индекса ячейки
        node<T>* bucketHead = this->arr[bucketIndex];
        while (bucketHead != NULL) // поиск в списке, который присутствует в ячейке по заданному ключу
        {
            if (bucketHead->key == key)
            {
                return bucketHead->value;
            }
            bucketHead = bucketHead->next; // переход к следующему node в списке
        }
        cout << "!Data not found!" << endl; // когда ключ не подобран
        return -1;
    }
};

int main()
{
    unordered_map<int> mp; // int - значение, в нашем случае key типа string
    mp.insert("Vlad", 111);
    mp.insert("Anton", 14);
    mp.insert("Bogdan", 2);
    mp.insert("Stas", 8);
    mp.insert("Zhenya", 14);
    mp.insert("Artur", 64);

    cout << "Value of Vlad : " << mp.search("Vlad") << endl;
    cout << "Value of Anton : " << mp.search("Anton") << endl;
    cout << "Value of Bogdan : " << mp.search("Bogdan") << endl;
    cout << "Value of Stas : " << mp.search("Stas") << endl;
    cout << "Value of Zhenya : " << mp.search("Zhenya") << endl;
    cout << "Value of Artur : " << mp.search("Artur") << endl;

    // выводит Data not found and return -1
    mp.search("Ivan"); // случай, когда в хеш-таблице отсутствует нужный ключ

    return 0;
}
