#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int	main ()
{
	printf("\n\n isalpha:");
	char isalpha_c = ',';

	printf("\nReal:\n\treturn \t= %d\n", isalpha(isalpha_c));
	printf("\nMine:\n\treturn \t= %d", ft_isalpha(isalpha_c));


	printf("\n\n isdigit:");
	int isdigit_nb = '1';

	printf("\nReal:\n\treturn \t= %d\n", isdigit(isdigit_nb));
	printf("\nMine:\n\treturn \t= %d", ft_isdigit(isdigit_nb));


int main(void)
{
	char c = 0;

	printf("Real:%d\n", isascii(c));
	printf("Mine:%d", ft_isascii(c));
	return (0);
}


int main(void)
{
	int nb = 31;

	printf("Real: %d\n", isprint(nb));
	printf("Mine: %d", ft_isprint(nb));

	return (0);
}


int main(void)
{
	char *str = "wohwoudhwuoigbiwadawdawdawdawyawgigwaiydgwaugiwag";

	printf("Real: %lu\n", strlen(str));
	printf("Mine: %lu", ft_strlen(str));

	return (0);
}



int	main ()
{
	char	str_og[10] = "";
	char	str_cp[10] = "";
	int		replace = 'a';
	int		replace2 = 'b';
	int		len = 4;

	memset(str_og, replace, len);
	memset(str_og+len, replace2, len);
	ft_memset(str_cp, replace, len);
	ft_memset(str_cp+len, replace2, len);
	printf("Real: %s\n", str_og);
	printf("Mine: %s", str_cp);
	return 0;
}



int	main ()
{
	char	src[] = "0123456789";
	char	str_og[] = "qwertyuiop";
	char	str_cp[] = "qwertyuiop";
	int		len = 11;

	memcpy(str_og, src, len);
	ft_memcpy(str_cp, src, len);
	printf("\nReal: %s", str_og);
	printf("\nMine: %s", str_cp);
	return 0;
}



int	main ()
{
	char	src[] = "0123456789";
	char	str_og[] = "qwertyuiop";
	char	str_cp[] = "qwertyuiop";
	int		len = 11;

	memcpy(str_og, src, len);
	ft_memcpy(str_cp, src, len);
	printf("\nReal: %s", str_og);
	printf("\nMine: %s", str_cp);
	return 0;
}


	printf("\n\n memset:");
	char	memset_og[10] = "";
	char	memset_cp[10] = "";
	int		memset_replace = 'a';
	int		memset_replace2 = 'b';
	int		memset_len = 4;

	memset(memset_og, memset_replace, memset_len);
	memset(memset_og+memset_len, memset_replace2, memset_len);
	ft_memset(memset_cp, memset_replace, memset_len);
	ft_memset(memset_cp+memset_len, memset_replace2, memset_len);
	printf("Real: %s\n", memset_og);
	printf("Mine: %s", memset_cp);


	printf("\n\nstrcmp:");
	char    memcmp_str1[] = "468\0464";
	char    memcmp_str2[] = "4683465789";
	int		memcmp_n = 4;

	printf("\nReal:\n\treturn \t= %d\n", memcmp(memcmp_str1, memcmp_str2, memcmp_n));
	printf("\nMine:\n\treturn \t= %d", ft_memcmp(memcmp_str1, memcmp_str2, memcmp_n));
	return (0);

	printf("\n\n bzero:");
	char bzero_og[] = "almost every programmer should know bzero!";
	char bzero_cp[] = "almost every programmer should know bzero!";
	int bzero_len = 0;

	bzero(bzero_og, bzero_len);
	ft_bzero(bzero_cp, bzero_len);
	printf("Real: %s\n",bzero_og);
	printf("Mine: %s", bzero_cp);



	char	src[] = "0123456789";
	char	str_og[] = "qwertyuiop";
	char	str_cp[] = "qwertyuiop";
	int		len = 11;

	memcpy(str_og, src, len);
	ft_memcpy(str_cp, src, len);
	printf("\nReal: %s", str_og);
	printf("\nMine: %s", str_cp);
	return 0;



int	main ()
{
	char	src[] = "0123456789";
	char	str_og[] = "qwertyuiop";
	char	str_cp[] = "qwertyuiop";
	int		len = 6;

	memmove(str_og, src, len);
	ft_memmove(str_cp, src, len);
	printf("\nReal: %s", str_og);
	printf("\nMine: %s", str_cp);
	return 0;
}


int	main ()
{
	char	src[] = "0123456789";
	char	dst_og[] = "qwertyuiop";
	char	dst_cp[] = "qwertyuiop";
	int		dstsize = 0;

	strlcpy(dst_og, src, dstsize);
	ft_strlcpy(dst_cp, src, dstsize);
	printf("\nReal: %s", dst_og);
	printf("\nMine: %s", dst_cp);
	return (0);
}



int	main ()
{
	char	src[] = "0123465789";
	char	dst_og[] = "qwerty";
	char	dst_cp[] = "qwerty";
	int		dstsize = 0;

	printf("\nReal:\n\tdst \t= %s\n\treturn \t= %lu\n", dst_og, strlcat(dst_og, src, dstsize));
	printf("\nMine:\n\tdst \t= %s\n\treturn \t= %lu", dst_cp, ft_strlcat(dst_cp, src, dstsize));
	return (0);
}




int	main ()
{
	int	ltr = 'a';

	printf("\nReal:\n\treturn \t= %d\n", toupper(ltr));
	printf("\nMine:\n\treturn \t= %d", ft_toupper(ltr));
	return (0);
}

	int	main ()
	{
		int	ltr = '1';

		printf("\nReal:\n\treturn \t= %d\n", tolower(ltr));
		printf("\nMine:\n\treturn \t= %d", ft_tolower(ltr));
		return (0);
	}


{
	char	chr = '';
	char	string[] = "bonjour";

	printf("\nReal:\n\treturn\t= %s\n", strchr(string, chr));
	printf("\nMine:\n\treturn\t= %s", ft_strchr(string, chr));
	return (0);
}

int	main ()
{
	char	chr = 'b';
	char	string[] = "bonjour";

	printf("\nReal:\n\treturn\t= %s\n", strrchr(string, chr));
	printf("\nMine:\n\treturn\t= %s", ft_strrchr(string, chr));
	return (0);
}


int	main(void)
{
	const char string1[] = "test€";
	const char string2[] = "test";
	size_t size = 6;

	printf("Real: %d\n", strncmp(string2, string1, size));
	printf("Test: %d", ft_strncmp(string2, string1, size));

	return (0);
}


//int main(void)
//{
//	char *string = NULL;
//	char *trim = " ";
//	char *dst;
//	//start_offset(string, trim);
//	//end_offset(string, trim);
//	dst = ft_strtrim(string, trim);
//	printf("\nft_strtrim\n\treturn = %s", dst);
//	return (0);
//}




int	main ()
{
	const char	haytstack[] = "Foo BarBaz";
	const char	needle[] = "Baz";
	int			len = 7;

	printf("\nReal:\n\treturn \t= %s\n", strnstr(haytstack, needle, len));
	printf("\nMine:\n\treturn \t= %s", ft_strnstr(haytstack, needle, len));
	return (0);
}


int	main(void)
{
	const char str[] = "+40";

	printf("\nReal:\n\treturn\t= %d\n", atoi(str));
	printf("\nMine:\n\treturn\t= %d", ft_atoi(str));

	return (0);
}


}
