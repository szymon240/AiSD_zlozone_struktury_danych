#include "OWlist.h"



oWlist* insert(int value, oWlist* start)
{
    oWlist* temp;
    oWlist* ptr = start;
    oWlist* insertion_element = new oWlist(value);
    while (true)
    {
        if (ptr->info > insertion_element->info)
        {
            if (ptr == start)
            {
                temp = ptr;
                start = insertion_element;
                insertion_element->next = temp;
            }
            //else
            //{
               // temp = ptr->next;
               // ptr->next = insertion_element;
               // insertion_element->next = temp;
            //}
            break;
        }
        else if (ptr->next != nullptr)
        {
            if (ptr->next->info > insertion_element->info)
            {
                temp = ptr->next;
                ptr->next = insertion_element;
                insertion_element->next = temp;
                break;
            }
        }
        else
        {
            ptr->next = insertion_element;
            break;
        }

        ptr = ptr->next;
    }
    return start;
}

oWlist* build_owlist(int* tab, int size, oWlist* start)
{
    start = new oWlist(tab[0]);
    for (int i = 1; i < size; i++)
    {
        start = insert(tab[i], start);
        //display_owlist(start);
    }
    return start;
}

void display_owlist(oWlist* start)
{
    oWlist* tempptr = start;
    while (tempptr != nullptr)
    {
        std::cout << tempptr->info << " ";
        tempptr = tempptr->next;
    }
    std::cout << std::endl;
}

oWlist* search_OWlist(oWlist* start, int x)
{
    oWlist* ptr = start;
    while (ptr->info != x)
    {
        ptr = ptr->next;
    }
   // std::cout << "Znaleziono: " << ptr->info << std::endl;
    return ptr;
}

oWlist* delete_OWlist(oWlist* start)
{
    oWlist* temp;
    while (start != nullptr)
    {
        temp = start->next;
        delete start;
        start = temp;
    }
        
    return start;
}

void Owlist_test()
{
    std::ofstream out;
    int lim, down, step;
    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow tworzenia struktury: ";
    std::cin >> down >> lim >> step;
    out.open("./OwListCreation.txt", std::fstream::out);
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i <= lim; i += step)
    {
        int* test_array = new int[i];
        create_random_array(test_array, i);
        oWlist* start = nullptr;
        auto start_time = std::chrono::steady_clock::now();
        build_owlist(test_array, i, start);
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] test_array;
    }
    out.close();


    out.open("./OwListSearch.txt", std::fstream::out);
    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow przeszukania struktury: ";
    std::cin >> down >> lim >> step;
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i < lim; i+= step)
    {
        int* search_array = new int[i];
        create_random_array(search_array, i);
        oWlist* search_list = nullptr;
        search_list = build_owlist(search_array, i, search_list);
        auto start_time = std::chrono::steady_clock::now();
        for (int j = 0; j < i; j++)
        {
            search_OWlist(search_list, search_array[j]);
        }
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] search_array;
    }
    out.close();

    std::cout << "Wybierz dolna, gorna granice, krok (po spacji) testow usuwania struktury: ";
    std::cin >> down >> lim >> step;
    out.open("./OwListDelete.txt", std::fstream::out);
    out << "LiczbaElementow\tCzas\n";
    for (int i = down; i <= lim; i += step)
    {
        int* test_array = new int[i];
        create_random_array(test_array, i);
        oWlist* start = nullptr;
        start = build_owlist(test_array, i, start);
        auto start_time = std::chrono::steady_clock::now();
        start = delete_OWlist(start);
        auto end_time = std::chrono::steady_clock::now();
        out << i << "\t" << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() << "\n";
        delete[] test_array;
    }
    out.close();

}
