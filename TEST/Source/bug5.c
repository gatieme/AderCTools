int main()
{
    for (start=0;ind<=token_ind;++start,++ind) /* Delete the leading white spaces. */
    {
        token_str[start]=token_str[ind];
    }
    return;
}