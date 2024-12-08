import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import Solution from './compoents/solution';
import 'bootstrap/dist/css/bootstrap.css'

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
    <React.StrictMode>
        {/* bootstrap: class=container
        控制窗口为自适应区域 */}
        <div className='container'>
            <Solution/>
        </div>
    </React.StrictMode>
);

