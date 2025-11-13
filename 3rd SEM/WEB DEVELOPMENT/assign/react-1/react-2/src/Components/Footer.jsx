import React from 'react'
import { Link } from 'react-router-dom'

const Footer = () => {
  return (
    <footer className="bg-gray-800 text-white py-6 mt-8">
    <div className="container mx-auto flex justify-between items-center">
      {/* Brand Name */}
      <div className="text-xl font-bold">
        Brand
      </div>
      
      {/* Footer Links */}
      <div className="flex space-x-6">
      <h1>BRAND</h1>
      </div>
      
      {/* Social Media Icons */}
      <div className="flex justify-center mt-6 space-x-4">
        <a href="https://facebook.com" target="_blank" rel="noopener noreferrer" className="hover:text-gray-400">
          <i className="fab fa-facebook fa-2x"></i>
        </a>
        <a href="https://twitter.com" target="_blank" rel="noopener noreferrer" className="hover:text-gray-400">
          <i className="fab fa-twitter fa-2x"></i>
        </a>
        <a href="https://instagram.com" target="_blank" rel="noopener noreferrer" className="hover:text-gray-400">
          <i className="fab fa-instagram fa-2x"></i>
        </a>
      </div>
    </div>

    {/* Footer Bottom */}
    <div className="text-center mt-4">
      <p className="text-sm">&copy; 2025 Brand. All rights reserved.</p>
    </div>
  </footer>
  )
}

export default Footer