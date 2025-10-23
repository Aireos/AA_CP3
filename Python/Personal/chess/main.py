#AKA Chess Pieces

from enum import Enum

class Color(Enum):
    white = 1
    black = 2

class Piece:
    def __init__(self, color, position):
        self.color = color
        self.position = position
    
    def __repr__(self):
        return f'{self.color.name}_{self.__class__.__name__} at {self.position}'
    
    def is_valid_move(self, new_position, board):
        raise NotImplementedError("Subclass must implement abstract method")

class Pawn(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific pawn move logic here
        pass

class Rook(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific rook move logic here
        pass

class Knight(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific knight move logic here
        pass

class Bishop(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific bishop move logic here
        pass

class Queen(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific queen move logic here
        pass

class King(Piece):
    def is_valid_move(self, new_position, board):
        # Implement specific king move logic here
        pass

class Game:
    def __init__(self):
        self.board = self.create_board()
        self.white_pieces = self.initialize_white_pieces()
        self.black_pieces = self.initialize_black_pieces()
        self.place_pieces_on_board()

    def create_board(self):
        return {f"{chr(file)}{rank}": None for file in range(ord('a'), ord('h') + 1) for rank in range(1, 9)}
    
    def initialize_white_pieces(self):
        pieces = []
        for file in "abcdefgh":
            pieces.append(Pawn(Color.white, f"{file}2"))
        pieces.append(Rook(Color.white, "a1"))
        pieces.append(Knight(Color.white, "b1"))
        pieces.append(Bishop(Color.white, "c1"))
        pieces.append(Queen(Color.white, "d1"))
        pieces.append(King(Color.white, "e1"))
        pieces.append(Bishop(Color.white, "f1"))
        pieces.append(Knight(Color.white, "g1"))
        pieces.append(Rook(Color.white, "h1"))
        return pieces

    def initialize_black_pieces(self):
        pieces = []
        for file in "abcdefgh":
            pieces.append(Pawn(Color.black, f"{file}7"))
        pieces.append(Rook(Color.black, "a8"))
        pieces.append(Knight(Color.black, "b8"))
        pieces.append(Bishop(Color.black, "c8"))
        pieces.append(Queen(Color.black, "d8"))
        pieces.append(King(Color.black, "e8"))
        pieces.append(Bishop(Color.black, "f8"))
        pieces.append(Knight(Color.black, "g8"))
        pieces.append(Rook(Color.black, "h8"))
        return pieces

    def place_pieces_on_board(self):
        for piece in self.white_pieces + self.black_pieces:
            self.board[piece.position] = piece

    def white_move(self, piece_position, new_position):
        if new_position not in self.board:
            print("That is not a correct location!")
            return False
        
        piece = self.board.get(piece_position)
        if not piece or piece.color != Color.white:
            print("No white piece at that starting position!")
            return False

    def print_board(self):
        board_rows = []
        for rank in range(8, 0, -1):
            row = []
            for file in "abcdefgh":
                pos = f"{file}{rank}"
                piece = self.board[pos]
                if piece:
                    symbol = self.get_piece_symbol(piece)
                    row.append(symbol)
                else:
                    row.append(" . ")
            board_rows.append("".join(row))
        print("\n".join(board_rows))
        
    def get_piece_symbol(self, piece):
        symbols = {
            (Color.white, "Pawn"): " ♙ ", (Color.black, "Pawn"): " ♟ ",
            (Color.white, "Rook"): " ♖ ", (Color.black, "Rook"): " ♜ ",
            (Color.white, "Knight"): " ♘ ", (Color.black, "Knight"): " ♞ ",
            (Color.white, "Bishop"): " ♗ ", (Color.black, "Bishop"): " ♝ ",
            (Color.white, "Queen"): " ♕ ", (Color.black, "Queen"): " ♛ ",
            (Color.white, "King"): " ♔ ", (Color.black, "King"): " ♚ ",
        }
        return symbols.get((piece.color, piece.__class__.__name__), " ? ")

if __name__ == "__main__":
    game = Game()
    game.print_board()
