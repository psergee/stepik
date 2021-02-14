// Write a function that checks if a string is palindrome recursively.

bool checkPalindrome(const string& s)
{
    if (s.size() <= 1)
        return true;
    return (s.front() != s.back()) ? false : checkPalindrome(s.substr(1, s.size()-2));
}
