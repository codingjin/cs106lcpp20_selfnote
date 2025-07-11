#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  std::vector<std::string::iterator> spaceits = find_all(source.begin(), source.end(), [](char c){return std::isspace(c);});
  size_t spaceits_length = spaceits.size();
  std::set<Token> tokens;
  std::transform(spaceits.begin(), spaceits.begin() + spaceits_length -1, spaceits.begin() + 1, std::inserter(tokens, tokens.end()), 
  [&source](auto it1, auto it2){
    return Token{source, it1, it2};
  });
  std::erase_if(tokens, [](auto token){return token.content.empty();});
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  auto misstoken_view = source | std::ranges::views::filter([&dictionary](auto token){return !dictionary.contains(token.content);});
  auto misspelling_suggestions_view = misstoken_view 
    | std::ranges::views::transform([&dictionary](auto token){
      auto suggestions_view = dictionary | std::ranges::views::filter([&token](const auto & word){
        return levenshtein(token.content, word) == 1;
      });
      std::set<std::string> suggestions(suggestions_view.begin(), suggestions_view.end());
      return Misspelling{token, suggestions};
    });

  auto misspelling_view = misspelling_suggestions_view 
    | std::ranges::views::filter([](const auto & misspelling) {return !misspelling.suggestions.empty();});
  std::set<Misspelling> misspelling_set(misspelling_view.begin(), misspelling_view.end());
  return misspelling_set;
};

/* Helper methods */

#include "utils.cpp"