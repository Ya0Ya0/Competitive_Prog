import { Chess } from 'chess.js';
import { Puzzle } from './puzzle';
import { toColor } from './util'

export function colour(x:string) {
  return (p: Puzzle) => {
    const chess = new Chess(p.analysis.fen)
    return x === '' || toColor(chess) === x
  }
}

export function severity(x:string) {
  return (p: Puzzle) => {
    return x === '' || p.analysis.judgment.name === x
  }
}

export function phase(x:string) {
  return (p: Puzzle) => {
    if (x === '') return true
    if (x == 'Opening') {
      return p.analysis.halfMove < 20
    }
    if (x === 'Endgame') {
      const fen = p.analysis.fen
      const pieces = fen.replace(/ .*$/,'').replace(/[0-9 pP-]/g,'')
      return pieces.length <= 7 + 6
    }
    
    const isOpening = p.analysis.halfMove < 20;
    const fen = p.analysis.fen
    const pieces = fen.replace(/ .*$/,'').replace(/[0-9 pP-]/g,'')
    const isEndgame = pieces.length <= 7 + 6
    return !isOpening && !isEndgame;
  }
}

export function timecontrol(x:string) {
  return (p: Puzzle) => {
    return x === '' || p.analysis.speed === x
  }
}