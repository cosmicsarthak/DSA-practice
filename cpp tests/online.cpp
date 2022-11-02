struct Paw
{
    int claws;
};

struct Animal
{
    string name;
    Paw paw;
};

int main()
{
    Animal puma{"Puma", {5}};

    Animal *ptr{&puma};

    // ptr is a pointer, use ->
    // paw is not a pointer, use .

    cout << (ptr->paw).claws << '\n';
    cerr << (*ptr).paw.claws << endl;

    cout << ptr->name << '\n';
    cerr << (*ptr).name << endl;
}