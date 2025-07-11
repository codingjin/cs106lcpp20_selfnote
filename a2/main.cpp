/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each Jin Huang
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <cctype>

std::string kYourName = "Jin Huang"; // Don't forget to change this!

std::string getInitials(const std::string& fullname) {
  std::istringstream iss(fullname);
  std::string word;
  std::string initials;

  while (iss >> word) {
    if (!word.empty()) {
      initials += std::toupper(word[0]);
    }
  }

  return initials;
}

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> applications;

  // open the file
  if (std::ifstream file{filename}) {
    std::string line;
    while (std::getline(file, line)) {
      //std::cout << line << std::endl;
      applications.emplace(line);
    }
  } else {
    std::cerr << "Could not open the file:" << filename << std::endl;
  }

  return applications;
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> matches;
  std::string initials_tomatch = getInitials(name);
  for (const auto& sfullname : students) {
    if (initials_tomatch == getInitials(sfullname)) {
      matches.push(&sfullname);
    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  std::string myinitials = getInitials(kYourName);
  while (!matches.empty()) {
    const std::string* temp_namep = matches.front();
    if (temp_namep->size() > 13) {
      std::cout << "Bingo! My soulmate is " << *temp_namep << std::endl;
      return *temp_namep;
    }
  }
  return std::string{"NO MATCHES FOUND"};
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
