import React, { Component } from 'react';

class Box extends Component {
    state = {  
        x: this.props.x,
    } 

    getStyles = () => {
        let styles = {
            width: "100px",
            height: "50px",
            backgroundColor: "lightblue",
            textAlign: "center",
            lineHeight: "50px",
            borderRadius: "5px",
            marginLeft: this.state.x + 10,   // 这里不需要加{}
        }
        if(this.state.x > 8)    // 9~   
            styles.backgroundColor = "orange";
        return styles;
    }



    render() { 
        console.log(this.props)
        return (
            <React.Fragment> 
                <div style={this.getStyles()}>{this.state.x}</div>
                <button type="button" onClick={this.handleClickLeft} className="btn btn-info  m-3">left</button>
                <button type="button" onClick={this.handleClickRight} className="btn btn-primary m-3" >right</button>
                <button type="button" onClick={() => this.props.onDelete(this.props.id)} className="btn btn-danger m-3" >delete</button>
            </React.Fragment>
        );
    }
}
 
export default Box;