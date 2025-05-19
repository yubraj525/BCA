import './App.css';
import Navbar from './Components/Navbar';
import About from './pages/About';
import { createBrowserRouter, RouterProvider, Outlet } from 'react-router-dom';
import Footer from './Components/Footer';
import Home from './pages/Home'; // Ensure you import Home, Service, Contactus, Login, and SignUp components
import Service from './pages/Service';
import Contactus from './pages/Contact';
import Login from './pages/Login';
import SignUp from './pages/SignUp';

function App() {
  const Layout=()=>{
    return(
      <>
      <Navbar/>
      <Outlet/>
      <Footer/>
      </>
      )
    }

    const routerLayout=createBrowserRouter([
      {
      path:"/",
      element:<Layout/>,
      children:[
        {path:"/",element:<Home/>},
        {path:"/about",element:<About/>},
        {path:"/service",element:<Service/>},
        {path:"/contactus",element:<Contactus/>},
      ],
    },
    {path:"/login",element:<Login/>},
    {path:"/signup",element:<SignUp/>},
  ]);
  return (
    <RouterProvider router={routerLayout} />
  );
  
}

    // mehod 1
    // <>
    // <Navbar/>
    //   <Routes>
    //     <Route path="/" element={<Home/>} />
    //     <Route path="/about" element={<About/>} />
    //     <Route path="/contactus" element={<Contact></Contact>} />
    //     <Route path="/service" element={<Service></Service>} />
    //     <Route path="/login" element={<Login></Login>} />
    //     <Route path="/signup" element={<SignUp>

    //     </SignUp>} />
       
      
    //   </Routes>
    //   <Footer/>
    // </>
  


export default App
