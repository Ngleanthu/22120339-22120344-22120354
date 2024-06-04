#include "exportStudentToCSV.h"

void exportStudentToCSV(Student* head, std::string filename) {
    std::ofstream file;
    file.open(filename + ".csv");
    if (!file)
    {
        std::cout << "Unable to create file." << endl;
        return;
    }
    file << "ID,Name,Date of Birth,Gender,Social ID" << endl;
    Student *current = head;
    while (current != nullptr)
    {
        file << current->id << "," << current->name << "," << current->dob.year << "-"
             << current->dob.month << "-" << current->dob.day << ","
             << (current->gender == Gender::0    ? "Male"
                 : current->gender == Gender::1 ? "Female"
                                                     : "Not say")
             << "," << current->social_id << endl;
        current = current->next;
    }
    file.close();
    std::cout << "Exported students to " << filename << ".csv" << endl;
}
