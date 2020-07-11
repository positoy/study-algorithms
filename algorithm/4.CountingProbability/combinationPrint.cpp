#include <iostream>

int buffer[1024], numbers[1024], count;

void init() {
    for (int i=0; i<1024; i++)
    numbers[i] = i;
    count = 0;
}

void swap(int x, int y) {
    int temp = numbers[x];
    numbers[x] = numbers[y];
    numbers[y] = temp;
}

void process(int size) {
    count++;
    for (int i=0; i<size; i++)
        std::cout << buffer[i] << ' ';
    std::cout << std::endl;
}

void permutation(int n, int r, int size) {
    if (r == 0) {
        process(size);
        return;
    }
    for (int i=n-1; i>=0; i--) {
        swap(n-1, i);
        buffer[r-1] = numbers[n-1];
        permutation(n-1,r-1,size);
        swap(i, n-1);
    }
}

void permutationDup(int n, int r, int size) {
    if (r == 0) {
        process(size);
        return;
    }
    for (int i=n-1; i>=0; i--) {
        swap(n-1, i);
        buffer[r-1] = numbers[n-1];
        permutationDup(n,r-1,size);
        swap(i, n-1);
    }
}

int main()
{
    int option,n,r;
    do {
        std::cout << "option: " << std::flush;
        std::cin >> option;
        std::cout << "enter: " << std::flush;
        std::cin >> n >> r;

        init();
        switch(option) {
            case 1:
            permutation(n,r,r);
            std::cout << "total: " << count << std::endl;
            break;
            case 2:
            permutationDup(n,r,r);
            std::cout << "total: " << count << std::endl;
            break;
        }
    } while(true);
}
