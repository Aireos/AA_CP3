from abc import ABC, abstractmethod
from enum import Enum
from chess_game import *

#main function to run
def main():
    game = ChessGame()
    game.print_board()
    while True:
        start_pos = input("What piece do you want to move? (type position of piece)(ex: a1): ")
        if start_pos not in game.board:
            print("Invalid position. Please enter a valid position (e.g., a1).")
            continue

        end_pos = input("Where do you want to move it? (type position)(ex: a3): ")
        if end_pos not in game.board:
            print("Invalid position. Please enter a valid position (e.g., a3).")
            continue

        result = game.move_piece(start_pos, end_pos)
        if result:
            break
        game.print_board()

main()