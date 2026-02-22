/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h-defines.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgertrud <lgertrud@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 13:22:54 by lgertrud          #+#    #+#             */
/*   Updated: 2025/09/25 16:06:18 by lgertrud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MENU "\n=============================\n" \
             "       PHONEBOOK MENU        \n" \
             "=============================\n" \
             "-> ADD    - Save a new contact\n" \
             "-> SEARCH - Search a contact\n" \
             "-> EXIT   - Quit the program\n" \
             "=============================\n"
			 
#define ADD "\n=============================\n" \
            "        ADD NEW CONTACT       \n" \
            "=============================\n"
#define SEARCH "\n===========================================\n" \
            "                   SEARCH                 \n" \
            "===========================================\n"

// ===== COLORS =====
#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_CYAN    "\033[1;36m"

// ===== SYMBOLS =====
#define SYMBOL_OK     COLOR_GREEN "\n[✔]" COLOR_RESET
#define SYMBOL_ERROR  COLOR_RED   "[✖]" COLOR_RESET
#define SYMBOL_WARN   COLOR_YELLOW "[!]" COLOR_RESET

// ===== MESSAGES =====
#define MSG_SUCCESS   SYMBOL_OK " Contact saved " COLOR_GREEN "successfully!" COLOR_RESET
#define MSG_REQUIRED  SYMBOL_WARN " This field is required!" COLOR_YELLOW" Try again." COLOR_RESET
#define MSG_INVALID   SYMBOL_ERROR " Invalid index!\n"
