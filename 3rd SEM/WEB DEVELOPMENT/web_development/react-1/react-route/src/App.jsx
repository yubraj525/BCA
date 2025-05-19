
import './App.css'
import { BrowserRouter, Routes, Route } from 'react-router-dom'
import First from './Component'



function App() {


  return (
    <>
    <BrowserRouter>
    <Routes>
      <Route path="/" element={<First/>} />
    </Routes>
  </BrowserRouter>
    </>
  )
}

export default App
