const path = require('path');
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const HtmlWebpackPlugin = require('html-webpack-plugin');
const WebpackMd5Hash = require('webpack-md5-hash'); // добавили плагин

module.exports = {
    entry: { main: './src/index.js' },
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: '[name].[chunkhash].js'
    },
// указали путь к файлу, в квадратных скобках куда вставлять сгенерированный хеш
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /node_modules/,
                use: {
                    loader: "babel-loader"
                }
            },
            {
                test: /\.css$/,
                use:  [MiniCssExtractPlugin.loader, 'css-loader', 'postcss-loader']
            },
            {
                test: /\.(png|jpg|gif|ico|svg)$/,
                use: [
                  'file-loader?name=./images/[name].[ext]',
                  {
                    loader: 'image-webpack-loader',
                    options: {
                        mozjpeg: {
                          progressive: true,
                          quality: 65
                        },
                        // optipng.enabled: false will disable optipng
                        optipng: {
                          enabled: false,
                        },
                        pngquant: {
                          quality: '65-90',
                          speed: 4
                        },
                        gifsicle: {
                          interlaced: false,
                        },
                        // the webp option will enable WEBP
                        webp: {
                          quality: 75
                        }
                      }
                  },
                ],
            },
            {
                test: /\.(woff|woff2|eot|ttf|otf)$/,
                loader: 'file-loader?name=./vendor/[name].[ext]'
            }
        ]
    },
    plugins: [ 
        new MiniCssExtractPlugin({
                filename: 'style.[contenthash].css'
        }),
        new HtmlWebpackPlugin({
            inject: false,
            hash: true,
            template: './src/index.html',
            filename: 'index.html'
        }),
        new WebpackMd5Hash()
    ]
};