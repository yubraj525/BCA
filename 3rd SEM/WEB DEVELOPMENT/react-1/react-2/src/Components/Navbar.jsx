import React from 'react'
import "./navbar.css"
import { Link } from 'react-router-dom'
const Navbar = () => {
  return (
    <>
       <nav className="bg-gray-800 p-4">
      <div className="container mx-auto flex justify-between items-center">
        <div className="text-white text-xl font-bold">Brand</div>
        
        <ol className="hidden md:flex space-x-6 text-white">
            <Link to="/">
          <li className="hover:text-gray-400 cursor-pointer">Home</li>
            </Link>
            <Link to="/about">
          <li className="hover:text-gray-400 cursor-pointer">About Us</li>
            </Link>
            <Link to="/service">
          <li className="hover:text-gray-400 cursor-pointer">Service</li>
            </Link>
            <Link to="/contactus">
          <li className="hover:text-gray-400 cursor-pointer">Contact Us</li>
            </Link>
        
        </ol>
        
        <div className="hidden md:flex space-x-4">
        <Link to='/login' >
          <button className="px-4 py-2 border border-white text-white rounded-lg hover:bg-white hover:text-gray-800">Login</button>
        </Link>
        <Link to='/signup'>
          <button className="px-4 py-2 bg-blue-500 text-white rounded-lg hover:bg-blue-600">Sign Up</button>
        </Link>
        </div>
      </div>
    </nav>
    </>
  )
}

export default Navbar