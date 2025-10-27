from abc import ABC, abstractmethod
from enum import Enum

class Color(Enum):
    white = 1
    black = 2

class ChessPiece(ABC):
    def __init__(self, color, position):
        self.color = color
        self.position = position

    def __repr__(self):
        return f'{self.color.name.capitalize()} {self.__class__.__name__}'

    @abstractmethod
    def can_move(self, new_position, board):
        pass
    
    @abstractmethod
    def symbol(self):
        pass

    def _is_path_clear(self, start_pos, end_pos, board):
        start_file, start_rank = ord(start_pos[0]), int(start_pos[1])
        end_file, end_rank = ord(end_pos[0]), int(end_pos[1])

        file = 0
        d_rank = 0
        if start_file < end_file: file = 1
        elif start_file > end_file: file = -1

        if start_rank < end_rank: d_rank = 1
        elif start_rank > end_rank: d_rank = -1
            
        current_file = start_file + file
        current_rank = start_rank + d_rank

        while current_file != end_file or current_rank != end_rank:
            position = f"{chr(current_file)}{current_rank}"
            if board.get_piece_at(position):
                return False
            current_file += file
            current_rank += d_rank
        return True

class Pawn(ChessPiece):
    def __init__(self, color, position):
        super().__init__(color, position)
        self.first_move = True
    
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])
        
        file = end_file - start_file
        d_rank = end_rank - start_rank
        
        direction = 1 if self.color == Color.white else -1

        if file == 0 and d_rank == direction:
            return not board.get_piece_at(new_position)
        
        if self.first_move and file == 0 and d_rank == 2 * direction:
            return not board.get_piece_at(new_position) and self._is_path_clear(self.position, new_position, board)
        
        if abs(file) == 1 and d_rank == direction:
            target_piece = board.get_piece_at(new_position)
            return target_piece and target_piece.color != self.color
            
        return False

    def promote(self):
        return Queen(self.color, self.position)  # Promotes to a Queen

    def symbol(self):
        return "♙ " if self.color == Color.white else "♟ "

class Rook(ChessPiece):
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])

        if start_file != end_file and start_rank != end_rank:
            return False
        
        if not self._is_path_clear(self.position, new_position, board):
            return False
            
        target_piece = board.get_piece_at(new_position)
        return not target_piece or target_piece.color != self.color

    def symbol(self):
        return "♖ " if self.color == Color.white else "♜ "

class Knight(ChessPiece):
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])
        
        file = abs(end_file - start_file)
        d_rank = abs(end_rank - start_rank)
        
        if not ((file == 1 and d_rank == 2) or (file == 2 and d_rank == 1)):
            return False
            
        target_piece = board.get_piece_at(new_position)
        return not target_piece or target_piece.color != self.color

    def symbol(self):
        return "♘ " if self.color == Color.white else "♞ "

class Bishop(ChessPiece):
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])
        
        file = abs(end_file - start_file)
        d_rank = abs(end_rank - start_rank)
        
        if file != d_rank:
            return False
        
        if not self._is_path_clear(self.position, new_position, board):
            return False
            
        target_piece = board.get_piece_at(new_position)
        return not target_piece or target_piece.color != self.color

    def symbol(self):
        return "♗ " if self.color == Color.white else "♝ "

class Queen(ChessPiece):
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])
        
        file = abs(end_file - start_file)
        d_rank = abs(end_rank - start_rank)
        
        is_linear = (file == 0 or d_rank == 0)
        is_diagonal = (file == d_rank)
        
        if not (is_linear or is_diagonal):
            return False
        
        if not self._is_path_clear(self.position, new_position, board):
            return False
            
        target_piece = board.get_piece_at(new_position)
        return not target_piece or target_piece.color != self.color

    def symbol(self):
        return "♕ " if self.color == Color.white else "♛ "

class King(ChessPiece):
    def can_move(self, new_position, board):
        start_file, start_rank = ord(self.position[0]), int(self.position[1])
        end_file, end_rank = ord(new_position[0]), int(new_position[1])
        
        file = abs(end_file - start_file)
        d_rank = abs(end_rank - start_rank)
        
        if not (file <= 1 and d_rank <= 1):
            return False
            
        target_piece = board.get_piece_at(new_position)
        return not target_piece or target_piece.color != self.color

    def symbol(self):
        return "♔ " if self.color == Color.white else "♚ "

class ChessGame:
    def __init__(self):
        self.board = {f"{chr(file)}{rank}": None for file in range(ord('a'), ord('h') + 1) for rank in range(1, 9)}
        self.white_pieces = []
        self.black_pieces = []
        self._initialize_pieces()
        self._place_pieces_on_board()
        self.current_turn = Color.white

    def _initialize_pieces(self):
        self.white_pieces.extend([Pawn(Color.white, f"{file}2") for file in "abcdefgh"])
        self.white_pieces.extend([
            Rook(Color.white, "a1"), Knight(Color.white, "b1"), Bishop(Color.white, "c1"),
            Queen(Color.white, "d1"), King(Color.white, "e1"), Bishop(Color.white, "f1"),
            Knight(Color.white, "g1"), Rook(Color.white, "h1")
        ])

        self.black_pieces.extend([Pawn(Color.black, f"{file}7") for file in "abcdefgh"])
        self.black_pieces.extend([
            Rook(Color.black, "a8"), Knight(Color.black, "b8"), Bishop(Color.black, "c8"),
            Queen(Color.black, "d8"), King(Color.black, "e8"), Bishop(Color.black, "f8"),
            Knight(Color.black, "g8"), Rook(Color.black, "h8")
        ])

    def _place_pieces_on_board(self):
        for piece in self.white_pieces + self.black_pieces:
            self.board[piece.position] = piece

    def get_piece_at(self, position):
        return self.board.get(position)

    def move_piece(self, start_pos, end_pos):
        piece = self.get_piece_at(start_pos)
        if not piece or piece.color != self.current_turn:
            print(f"No piece found at {start_pos} or it's not your turn.")
            return False

        if not piece.can_move(end_pos, self):
            print(f"Invalid move for {piece} from {start_pos} to {end_pos}")
            return False

        target_piece = self.get_piece_at(end_pos)
        if target_piece:
            self.remove_piece(target_piece)

        self.board[start_pos] = None
        piece.position = end_pos
        self.board[end_pos] = piece

        if isinstance(piece, Pawn) and (end_pos[1] == '8' or end_pos[1] == '1'):
            piece = piece.promote()
            self.board[end_pos] = piece
        
        if self.is_king_in_check(self.current_turn):
            print(f"Move puts {self.current_turn.name.capitalize()}'s king in check! Move is invalid.")
            piece.position = start_pos
            self.board[start_pos] = piece
            self.board[end_pos] = None
            return False

        if self.is_checkmate(self.current_turn):
            print(f"Checkmate! {self.current_turn.name.capitalize()} loses!")
            return True
        
        if self.is_stalemate(self.current_turn):
            print("Stalemate! The game is drawn.")
            return True

        self.current_turn = Color.black if self.current_turn == Color.white else Color.white
        print(f"Moved {piece} from {start_pos} to {end_pos}")
        return False

    def remove_piece(self, piece):
        if piece.color == Color.white:
            self.white_pieces.remove(piece)
        else:
            self.black_pieces.remove(piece)
        print(f"Captured: {piece}")

    def is_king_in_check(self, color):
        king_position = None
        for piece in (self.white_pieces if color == Color.white else self.black_pieces):
            if isinstance(piece, King):
                king_position = piece.position
                break

        if not king_position:
            return False

        for piece in (self.black_pieces if color == Color.white else self.white_pieces):
            if piece.can_move(king_position, self):
                return True
        return False

    def is_checkmate(self, color):
        if not self.is_king_in_check(color):
            return False

        for piece in (self.white_pieces if color == Color.white else self.black_pieces):
            for file in "abcdefgh":
                for rank in range(1, 9):
                    new_position = f"{file}{rank}"
                    if piece.can_move(new_position, self):
                        original_position = piece.position
                        self.board[original_position] = None
                        piece.position = new_position
                        self.board[new_position] = piece

                        if not self.is_king_in_check(color):
                            piece.position = original_position
                            self.board[original_position] = piece
                            self.board[new_position] = None
                            return False

                        piece.position = original_position
                        self.board[original_position] = piece
                        self.board[new_position] = None
        
        return True

    def is_stalemate(self, color):
        if self.is_king_in_check(color):
            return False 

        for piece in (self.white_pieces if color == Color.white else self.black_pieces):
            for file in "abcdefgh":
                for rank in range(1, 9):
                    new_position = f"{file}{rank}"
                    if piece.can_move(new_position, self):
                        return False
        return True

    def print_board(self):
        print("\n  " + "  ".join("abcdefgh"))
        for rank in range(8, 0, -1):
            row = [str(rank)]
            for file in "abcdefgh":
                pos = f"{file}{rank}"
                piece = self.get_piece_at(pos)
                row.append(piece.symbol() if piece else ". ")
            print(" ".join(row))

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